function createTodoElement(todo) {
  if (!todo) return null;

  const liElement = document.createElement('li');
  liElement.textContent = todo.title;
  liElement.dataset.id = todo.id;

  return liElement;
}

function renderTodoList(todoList, ulElementId) {
  const ulElement = document.getElementById(ulElementId);

  if (ulElement) {
    for (let i = 0; i < todoList.length; i++) {
      const liElement = createTodoElement(todoList[i]);
      ulElement.appendChild(liElement);
    }
  }
}

// main
(() => {
  const todoList1 = [
    { id: 1, title: 'Learn Javascript' },
    { id: 2, title: 'Learn ReactJS' },
    { id: 3, title: 'Learn NextJS' },
  ];

  renderTodoList(todoList1, 'todoList');
})();
