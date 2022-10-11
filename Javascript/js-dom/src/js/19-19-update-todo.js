const createTodoList = (todo) => {
  if (!todo) return;

  // find template
  const todoTemplate = document.getElementById('todoTemplate');
  if (!todoTemplate) return null;

  // clone li element
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

  // add click event for edit button
  const editButton = todoElement.querySelector('button.edit');
  if (editButton) {
    editButton.addEventListener('click', () => {
      // populate data to todo form
      populateTodoForm(todo);
    });
  }

  return todoElement;
};

const populateTodoForm = () => {
  // query todo form
  // dataset.id = todo.id
};

const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList) || todoList.length === 0) return null;

  let todoListLength = todoList.length;

  const ulListElement = document.getElementById(ulElement);
  if (!ulListElement) return;

  for (let i = 0; i < todoListLength; i++) {
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

  const todoText = todoInput.value;
  if (!todoText) return;
  const newTodo = {
    id: Date.now(),
    title: todoText,
    status: 'pending',
  };

  // save
  const todoList = getTodoList();
  todoList.push(newTodo);
  localStorage.setItem('todo_list', JSON.stringify(todoList));

  // apply DOM change
  const newLiElement = createTodoList(newTodo);
  const ulListElement = document.getElementById('todoList');
  if (!ulListElement) return;
  ulListElement.appendChild(newLiElement);

  // reset form
  const todoForm = document.getElementById('todoFormId');
  if (todoForm) todoForm.reset();
};

// main
(() => {
  const todoList = getTodoList();

  renderTodoList(todoList, 'todoList');

  // register submit event for todo form
  const todoForm = document.getElementById('todoFormId');
  if (todoForm) {
    todoForm.addEventListener('submit', handleTodoFormSubmit);
  }
})();
