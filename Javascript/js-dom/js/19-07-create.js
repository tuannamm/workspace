function renderTodoList(ulElement) {
  const todoList = [
    { id: 1, title: 'Learn Javascript' },
    { id: 2, title: 'Learn ReactJS' },
    { id: 3, title: 'Learn NextJS' },
  ];

  const ulElement = document.getElementById(ulElement);
  if (ulElement) {
    for (let i = 0; i < todoList.length; i++) {
      const liElement = document.createElement('li');
      liElement.textContent = todoList[i].title;
      ulElement.appendChild(liElement);
    }
  }
}

(() => {
  renderTodoList();
})();
