import React, { useState } from "react";

const TodoList = () => {
  // const [todo, setTodo] = useState("");
  // const [todos, setTodos] = useState(() => {
  //   const storageJobs = JSON.parse(localStorage.getItem("jobs"));
  //   return storageJobs ?? [];
  // });
  // const handleSubmit = () => {
  //   setTodos((prev) => {
  //     const newJobs = [...prev, todo];

  //     const jsonJobs = JSON.stringify(newJobs);
  //     localStorage.setItem("jobs", jsonJobs);

  //     return newJobs;
  //   });
  //   setTodo("");
  // };

  // return (
  //   <>
  //     <input value={todo} onChange={(e) => setTodo(e.target.value)} />
  //     <button onClick={handleSubmit}>ADD</button>
  //     <ul>
  //       {todos.map((todo, index) => (
  //         <li key={index}>{todo}</li>
  //       ))}
  //     </ul>
  //   </>
  // );

  const [todo, setTodo] = useState("");
  const [todos, setTodos] = useState(() => {
    const storageJobs = JSON.parse(localStorage.getItem("jobs"));
    return storageJobs ?? [];
  });

  const handleSubmit = () => {
    setTodos((prev) => {
      const newJobs = [...prev, todo];
      setTodo("");
      const jsonJobs = JSON.stringify(newJobs);
      localStorage.setItem("jobs", jsonJobs);
      return newJobs;
    });
  };

  return (
    <>
      <input value={todo} onChange={(e) => setTodo(e.target.value)} />
      <button onClick={handleSubmit}>ADD</button>
      <ul>
        {todos.map((todo, index) => (
          <li key={index}>{todo}</li>
        ))}
      </ul>
    </>
  );
};

export default TodoList;
