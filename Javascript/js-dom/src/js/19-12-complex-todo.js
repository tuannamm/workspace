const createTodoList = (todo) => {
  if (!todo) return;
};

const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList) || todoList.length === 0) return null;

  const ulListElement = document.getElementById('todoList');
  if (!ulListElement);

  for (let i = 0; i < todoList.length; i++) {
    const liElement = createTodoList(todoList[i]);
  }
};

// main
(() => {
  const todoList = [
    { id: 1, title: 'Learn Javascript' },
    { id: 2, title: 'Learn ReactJS' },
    { id: 3, title: 'Learn NextJS' },
  ];
  renderTodoList(todoList, 'todoList');
})();
