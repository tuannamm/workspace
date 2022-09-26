import React, { useLayoutEffect, useState } from "react";
/*
  useEffect
  1. Cập nhật lại state
  2. Cập nhật DOM (mutated)
  3. Render lại UI
  4. Gọi cleanup nếu deps thay đổi
  5. Gọi useEffect callback

  useLayoutEffect
  1. Cập nhật state
  2. Cập nhật DOM (mutated)
  3. Gọi cleanup nếu deps thay đổi (sync)
  4. Gọi useLayoutEffect callback (sync)
  5. Render lại UI
*/
const MyCount = () => {
  const [count, setCount] = useState(0);

  useLayoutEffect(() => {
    if (count > 3) setCount(0);
  }, [count]);

  const handleClick = () => {
    setCount((prev) => prev + 1);
  };

  return (
    <div>
      <h1>{count}</h1>
      <button onClick={handleClick}>Click</button>
    </div>
  );
};
export default MyCount;
