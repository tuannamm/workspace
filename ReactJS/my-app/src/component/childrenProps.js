import React from "react";

const ChildrenProps = ({ data, children }) => {
  return <ul>{data.map((car) => children(car))}</ul>;
};

export default ChildrenProps;
