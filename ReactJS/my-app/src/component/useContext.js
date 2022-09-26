import { useContext } from "react";
import Content from "./Content";
import { ThemeContext } from "./ThemeContext";
// Context
// CompA => Comp B => CompC

// 1. Create context
// 2. Provider
// 3. Consumber

const MyUseContext = () => {
  const context = useContext(ThemeContext);

  return (
    <>
      <button onClick={context.toggleTheme}>Change theme</button>
      <Content />
    </>
  );
};

export default MyUseContext;
