import { useCallback, useEffect } from "react";

export default function App() {
  // handle what happens on key press
  const handleKeyPress = useCallback((event) => {
    if (event.key === "Enter") console.log("xxxxx");
  }, []);

  useEffect(() => {
    // attach the event listener
    document.addEventListener("keydown", handleKeyPress);

    // remove the event listener
    return () => {
      document.removeEventListener("keydown", handleKeyPress);
    };
  }, [handleKeyPress]);

  return (
    <div>
      <h1>Hello world</h1>
    </div>
  );
}
