function createTodoElement(todo) {
  if (!todo) return null;

  const liElement = document.createElement('li');
  liElement.textContent = todo.title;
  liElement.dataset.id = todo.id;

  return liElement;
}

function renderTodoList(todoList, ulElementId) {
  if (!Array.isArray(todoList) || todoList.length === 0) return;

  // find ulElement
  // loop through todoList
  // each todo --> create li element --> append to ul
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

  const todoList2 = [
    { id: 1, title: 'Learn English' },
    { id: 2, title: 'Learn Korean' },
  ];
  renderTodoList(todoList2, 'todoList');
})();
