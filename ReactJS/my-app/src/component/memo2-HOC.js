import React from "react";

const Show = ({ onIncrease }) => {
  console.log("hâhhah");
  return (
    <>
      <h1>HELLO</h1>;<button onClick={onIncrease}>Click</button>
    </>
  );
};
export default React.memo(Show);
