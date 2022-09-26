import { ThemeContext } from "./ThemeContext";
import { useContext } from "react";

const Paragraph = () => {
  const context = useContext(ThemeContext);

  return (
    <div className={context.theme}>
      <h1>HELLOOOOOOOOO</h1>
    </div>
  );
};

export default Paragraph;
