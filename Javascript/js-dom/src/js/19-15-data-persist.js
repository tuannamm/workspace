const renderTodoList = (todoList, ulElement) => {};

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
