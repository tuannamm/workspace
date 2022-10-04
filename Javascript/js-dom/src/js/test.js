const createTodoList = (todo) => {
  if (!todo) return;

  const todoTemplate = document.getElementById('todoTemplate');
  if (!todoTemplate) return null;

  const todoElement = todoTemplate.content.firstElementChild.cloneNode(true);
  todoElement.dataset.id = todo.id;
  todoElement.dataset.status = todo.status;

  const divElement = todoElement.querySelector('div.todo');
  if (!divElement) return;
  if (divElement) {
    const alertClass = todo.status === 'completed' ? 'alert-success' : 'alert-second';
    divElement.classList.remove('alert-secondary');
    divElement.classList.add(alertClass);
  }

  const titleElement = todoElement.querySelector('.todo__title');
  if (titleElement) titleElement.textContent = todo.title;

  const markAsDoneButton = todoElement.querySelector('button.mark-as-done');
  if (markAsDoneButton) {
    markAsDoneButton.addEventListener('click', () => {
      const currentStatus = todoElement.dataset.status;
      todoElement.dataset.status = currentStatus === 'pending' ? 'completed' : 'pending';
      const newAlertClass = currentStatus === 'pending' ? 'alert-success' : 'alert-secondary';
      divElement.classList.remove('alert-success', 'alert-secondary');
      divElement.classList.add(newAlertClass);
    });
  }

  const removeButton = todoElement.querySelector('.button.remove');
  if (removeButton) {
    removeButton.addEventListener('click', () => {
      todoElement.remove();
    });
  }
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

// main
(() => {
  const todoList = [
    { id: 1, title: 'Learn Javascript', status: 'pending' },
    { id: 2, title: 'Learn ReactJS', status: 'completed' },
    { id: 3, title: 'Learn NextJS', status: 'pending' },
  ];

  // const todoList = getTodoList();
  renderTodoList(todoList, 'todoList');
})();
