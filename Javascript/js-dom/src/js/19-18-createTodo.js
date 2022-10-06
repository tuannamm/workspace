const createTodoList = (todo) => {
  if (!todo) return;

  // find template
  const todoTemplate = document.getElementById('todoTemplate');
  if (!todoTemplate) return null;

  // clone li elementt
  const todoElement = todoTemplate.content.firstElementChild.cloneNode(true);
  todoElement.dataset.id = todo.id;
  todoElement.dataset.status = todo.status;

  // render todo status
  const divElement = todoElement.querySelector('div.todo');
  if (!divElement) return;
  if (divElement) {
    const alertClass = todo.status === 'completed' ? 'alert-success' : 'alert-secondary';
    divElement.classList.remove('alert-secondary');
    divElement.classList.add(alertClass);
  }

  // update content
  const titleElement = todoElement.querySelector('.todo__title');
  if (titleElement) titleElement.textContent = todo.title;

  // add click events for mark-as-done button
  const markAsDoneButton = todoElement.querySelector('button.mark-as-done');
  if (markAsDoneButton) {
    markAsDoneButton.addEventListener('click', () => {
      const currentStatus = todoElement.dataset.status;
      const newStatus = currentStatus === 'pending' ? 'completed' : 'pending';

      // get current todoList
      // update status of current todo
      // save to local storage
      const todoList = getTodoList();
      const index = todoList.findIndex((x) => x.id === todo.id);
      if (index >= 0) {
        todoList[index].status = newStatus;
        localStorage.setItem('todo_list', JSON.stringify(todoList));
      }

      // update data-status on li element
      todoElement.dataset.status = newStatus;

      // update alert class accordingly
      const newAlertClass = currentStatus === 'pending' ? 'alert-success' : 'alert-secondary';
      divElement.classList.remove('alert-success', 'alert-secondary');
      divElement.classList.add(newAlertClass);
    });
  }

  // add click event for remove button
  const removeButton = todoElement.querySelector('button.remove');
  if (removeButton) {
    removeButton.addEventListener('click', () => {
      // save to local storage
      const todoList = getTodoList();
      const newTodoList = todoList.filter((x) => x.id !== todo.id);
      localStorage.setItem('todo_list', JSON.stringify(newTodoList) || []);

      // remove
      todoElement.remove();
    });
  }

  return todoElement;
};

const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList) || todoList.length === 0) return null;

  const ulListElement = document.getElementById(ulElement);
  if (!ulListElement) return;

  for (let i = 0; i < todoList.length; i++) {
    const liElement = createTodoList(todoList[i]);
    ulListElement.appendChild(liElement);
  }
};

const getTodoList = () => {
  try {
    return JSON.parse(localStorage.getItem('todo_list'));
  } catch {
    return [];
  }
};

const handleTodoFormSubmit = (e) => {
  e.preventDefault();

  // get form value
  // validate form value
  // sale
  // apply DOM changes
  const todoInput = document.getElementById('todoText');
  if (!todoInput) return;
};

// main
(() => {
  // const todoList = [
  //   { id: 1, title: 'Learn Javascript', status: 'pending' },
  //   { id: 2, title: 'Learn ReactJS', status: 'completed' },
  //   { id: 3, title: 'Learn NextJS', status: 'pending' },
  // ];

  const todoList = getTodoList();

  renderTodoList(todoList, 'todoList');

  // register submit event for todo form
  const todoForm = document.getElementById('todoForm');
  if (todoForm) {
    todoForm.addEventListener('submit', handleTodoFormSubmit);
  }
})();
