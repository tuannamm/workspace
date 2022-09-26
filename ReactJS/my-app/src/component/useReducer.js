import { useReducer } from "react";

// useState làm được thì useReducer làm được và ngược lại

// useState
// 1. init state: 0
// 2. action: up (state + 1) / down (state - 1)

// useReducer
// 1. init state: 0
// 2. action: up (state + 1) / down (state - 1)
// 3. reducer
// 4. dispatch

// init state
const initState = 0;

// actions
const UP_ACTION = "up";
const DOWN_ACTION = "down";

// reducer
const reducer = (state, action) => {
  switch (action) {
    case UP_ACTION:
      return state + 1;
    case DOWN_ACTION:
      return state - 1;
    default:
      throw new Error("Invalid action");
  }
};

const MyUseReducer = () => {
  const [count, dispatch] = useReducer(reducer, initState);

  return (
    <>
      <h1>{count}</h1>
      <button onClick={() => dispatch(UP_ACTION)}>Up</button>
      <button onClick={() => dispatch(DOWN_ACTION)}>Down</button>
    </>
  );
};

export default MyUseReducer;
