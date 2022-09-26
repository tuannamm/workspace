import React from "react";

const Keys = () => {
  const listCourse = [
    {
      id: "p",
      name: "php",
    },
    {
      id: "ja",
      name: "java",
    },
    {
      id: "js",
      name: "javascript",
    },
  ];

  const course = listCourse.map((course) => (
    <h4 key={course.id}>{course.name}</h4>
  ));

  return (
    <>
      <h2>KEYS</h2>
      <ul>{course}</ul>
    </>
  );
};

export default Keys;
