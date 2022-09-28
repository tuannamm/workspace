const createTodoElement = (todo) => {
  if (!todo) return;

  // find template
  const todoTemplate = document.getElementById('todoTemplate');
  if (!todoTemplate) return null;

  // clone li element
  const createTodoElement = todoTemplate.content.firstElementChild.cloneNode(true);

  // update content where needed

  const liElement = document.createElement('li');
  liElement.innerText = todo.title;
  liElement.dataset = todo.id;

  return liElement;
};

const renderTodoList = (todoList, ulElement) => {
  if (!Array.isArray(todoList)) return;

  const ulElement = document.getElementById(ulElement);

  if (ulElement) {
    for (let i = 0; i < todoList.length; i++) {
      const liElement = createTodoElement(todoList[i]);
      ulElement.appendChild(liElement);
    }

    return ulElement;
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
