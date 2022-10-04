const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList) || todoList.length === 0) return;

  const ulListElement = document.getElementById(ulElement);
  if (!ulListElement) return;

  for (let i = 0; i < todoList.length; i++) {
    const liElement = createTodoList(todoList[i]);
    ulListElement.appendChild(liElement);
  }
};

const getTodoList = () => {
  try {
    return JSON.parse(localStorage.getItem('todo__list') || []);
  } catch (error) {
    return [];
  }
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
})();
