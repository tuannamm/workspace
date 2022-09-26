import React from "react";

const List = () => {
  const list = ["php", "java", "javascript"];
  const course = list.map((course) => <h4>{course}</h4>);
  return (
    <>
      <h1>LIST</h1>
      <h3>KHOÁ HỌC</h3>
      <ul>
        <h5>{course}</h5>
      </ul>
    </>
  );
};

export default List;
