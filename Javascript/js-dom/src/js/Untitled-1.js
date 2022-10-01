const createTodoList = (todo) => {
  if (!todo) return;

  // find template
  const todoElement = document.getElementById('todoTemplate');
  // clone

  // render li list todo
};

const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList) || todoList.length === 0) return null;

  const ulListElement = document.getElementById('todoList');
  if (!ulListElement) return;

  for (let i = 0; i < todoList.length; i++) {
    const liListElement = createTodoList(todoList[i]);
    ulListElement.appendChild(liListElement);
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
