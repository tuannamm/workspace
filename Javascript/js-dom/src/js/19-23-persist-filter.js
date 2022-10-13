const getAllTodoElements = () => {
  return document.querySelectorAll('#todoList > li');
};

const inMatchStatus = (liElement, filterStatus) => {
  return filterStatus === 'all' || liElement.dataset.status === filterStatus;
};

const isMatchSearch = (liElement, searchTerm) => {
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

const isMatch = (liElement, params) => {
  return (
    isMatchSearch(liElement, params.get('searchTerm')) &&
    inMatchStatus(liElement, params.get('status'))
  );
};

const searchTodo = (searchTerm) => {
  const todoElementList = getAllTodoElements();

  for (const todoElement of todoElementList) {
    const needToShow = isMatch(todoElement, searchTerm);
    todoElement.hidden = !needToShow;
  }
};

const handleFilterChange = (filterName, filterValue) => {
  // update query params
  const url = new URL(window.location);
  url.searchParams.set(filterName, filterValue);

  history.pushState({}, '', url);

  const todoElementList = getAllTodoElements();

  for (const todoElement of todoElementList) {
    const needToShow = isMatch(todoElement, url.searchParams);
    todoElement.hidden = !needToShow;
  }
};

const initSearchInput = (params) => {
  // find search term input
  const searchInput = document.getElementById('searchTerm');
  if (!searchInput) return;

  if (params.get('status')) {
    searchInput.value = params.get('status');
  }

  // attach change event
  searchInput.addEventListener('input', () => {
    // searchTodo(searchInput.value);
    handleFilterChange('searchTerm', searchInput.value);
  });
};

const filterTodo = (filterStatus) => {
  const todoElementList = getAllTodoElements();

  for (const todoElement of todoElementList) {
    const needToShow = filterStatus === 'all' || todoElement.dataset.status === filterStatus;
    todoElement.hidden = !needToShow;
  }
};

const initFilterStatus = (params) => {
  // find select
  const filterStatusSelect = document.getElementById('statusFilter');
  if (!filterStatusSelect) return;

  if (params.get('searchTerm')) {
    searchInput.value = params.get('searchTerm');
  }

  // attach change event
  filterStatusSelect.addEventListener('change', () => {
    filterTodo(filterStatusSelect.value);
    handleFilterChange('status', filterStatusSelect.value);
  });
};

// main
(() => {
  const params = new URLSearchParams(window.location.search);
  initSearchInput(params);
  initFilterStatus(params);
})();
