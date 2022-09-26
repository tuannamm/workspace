import { useState, memo } from "react";
import Show from "./memo2-HOC";

// 1. memo() -> Higher Order Component (HOC)
// 2. useCallback()

// Hooks
// HOC
// Render props

// memo: ghi nhớ lại props của component để quyết định có render lại component đó hay không -> tối ưu hiệu năng
// dùng để xử lý component tránh re-render trong tình huống không cần thiết

const MyMemo = () => {
  const [count, setCount] = useState(0);

  const increase = () => {
    setCount((prev) => prev + 1);
  };

  return (
    <>
      <h1>{count}</h1>
      <button onClick={increase}>Click</button>
      <Show />
    </>
  );
};

export default memo(MyMemo);
