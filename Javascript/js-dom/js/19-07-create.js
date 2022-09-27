function createTodoElement(todo) {
  if (!todo) return null;

  const liElement = document.createElement('li');
}

function renderTodoList(ulElementId) {
  const todoList = [
    { id: 1, title: 'Learn Javascript' },
    { id: 2, title: 'Learn ReactJS' },
    { id: 3, title: 'Learn NextJS' },
  ];

  const ulElement = document.getElementById(ulElementId);

  if (ulElement) {
    for (let i = 0; i < todoList.length; i++) {
      const liElement = document.createElement('li');

      liElement.textContent = todoList[i].title;

      liElement.dataset = todoList[i].id;

      ulElement.appendChild(liElement);
    }
  }
}

// main
(() => {
  renderTodoList('todoList');
})();
