const getAllTodoElements = () => {
  return document.querySelectorAll('#todoList > li');
};

const isMatch = (liElement, searchTerm) => {
  if (!liElement) return false;
  if (searchTerm === '') return true;

  // searchTerm === empty => show all todo
  // searchTerm !== empty => filter todo

  const titleElement = liElement.querySelector('p.todo__title');
  if (!titleElement) return false;

  const title = titleElement.textContent;
  if (!title) return false;

  return title.toLowerCase().includes(searchTerm.toLowerCase());
};

const searchTodo = (searchTerm) => {
  const todoElementList = getAllTodoElements();

  for (const todoElement of todoElementList) {
    const needToShow = isMatch(todoElement, searchTerm);
    todoElement.hidden = !needToShow;
  }
};

const handleFilterChange = (filterName, filterValue) => {
  const url = new URL(window.location);
  url.searchParams.set(filterName, filterValue);

  history.pushState({}, '', url);
};

const initSearchInput = () => {
  // find search term input
  const searchInput = document.getElementById('searchTerm');
  if (!searchInput) return;

  // attach change event
  searchInput.addEventListener('input', () => {
    searchTodo(searchInput.value);
  });
};

const filterTodo = (filterStatus) => {
  const todoElementList = getAllTodoElements();

  for (const todoElement of todoElementList) {
    const needToShow = filterStatus === 'all' || todoElement.dataset.status === filterStatus;
    todoElement.hidden = !needToShow;
  }
};

const initFilterStatus = () => {
  // find select
  const filterStatusSelect = document.getElementById('statusFilter');
  if (!filterStatusSelect) return;

  // attach change event
  filterStatusSelect.addEventListener('change', () => {
    filterTodo(filterStatusSelect.value);
    handleFilterChange('status', filterStatusSelect.value);
  });
};

// main
(() => {
  initSearchInput();
  initFilterStatus();
})();
