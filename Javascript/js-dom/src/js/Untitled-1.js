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
