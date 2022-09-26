import { useRef, useState, useEffect } from "react";

// Lưu các giá trị qua một tham chiếu bên ngoài function component

const CountDown = () => {
  const [count, setCount] = useState(60);

  const timeId = useRef();
  const prevCount = useRef();

  useEffect(() => {
    prevCount.current = count;
  }, [count]);

  const handleStart = () => {
    timeId.current = setInterval(() => {
      setCount((prev) => prev - 1);
    }, 1000);
  };

  const handleStop = () => {
    clearInterval(timeId.current);
  };

  return (
    <>
      <h1>Count: {count}</h1>
      <h2>PrevCount: {prevCount.current}</h2>
      <button onClick={handleStart}>Start</button>
      <button onClick={handleStop}>Stop</button>
    </>
  );
};

export default CountDown;
