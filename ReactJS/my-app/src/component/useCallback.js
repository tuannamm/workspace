import { useState, useCallback } from "react";
import Show from "./memo2-HOC";

// 1.memo() -> Higher Order Component (HOC)
// 2. useCallbacl()
// - Reference types
// - React memo()

const MyCallback = () => {
  const [count, setCount] = useState(0);

  const handleClick = () => {
    setCount((prev) => prev + 1);
  };

  return (
    <>
      <Show onIncrease={handleClick} />
      <h1>{count}</h1>
    </>
  );
};

export default MyCallback;
