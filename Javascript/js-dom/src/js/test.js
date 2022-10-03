const createTodoList = (todo) => {
  if (!todo) return;

  // find template
  const todoTemplate = document.getElementById('todoTemplate');
  if (!todoTemplate) return null;

  // clone
  const liTodoElement = todoTemplate.content.firstElementChild.cloneNode(true);

  // update content
  const titleElement = liTodoElement.querySelector('.todo__title');
  if (titleElement) titleElement.textContent = todo.title;
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
