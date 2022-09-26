import "./App.css";
import ButtonClick from "./component/buttonClick";
import Change from "./component/change";
import Form from "./component/form";
import Conditional from "./component/conditionalRendering";
import ShowHide from "./component/showHide";
import List from "./component/list";
import Keys from "./component/keys";
import ConvertMoney from "./component/convertMoney";
import Learn from "./component/props";
import Button from "./component/checkboxForm";
import ChildrenProps from "./component/childrenProps";
import RandomNumberHook from "./component/randomNumberHook";
import TodoList from "./component/todoList";
import Content from "./component/useEffect";
import MyApp from "./component/useLayoutEffect";
import CountDown from "./component/useRef";
import MyMemo from "./component/memo-HOC";
import MyUseMemo from "./component/useMemo";
import MyUseReducer from "./component/useReducer";
import TodoList2 from "./component/todoList-useReducer";
import Apps from "./component/test";

function App() {
  const cars = ["BMW", "Honda", "Toyota"];
  return (
    <>
      <ButtonClick />;<div>-------------------------------------------</div>
      <Change />
      <div>-------------------------------------------</div>
      <Form />
      <div>-------------------------------------------</div>
      <Conditional />
      <div>-------------------------------------------</div>
      <ShowHide />
      <div>-------------------------------------------</div>
      <List />
      <div>-------------------------------------------</div>
      <Keys />
      <div>-------------------------------------------</div>
      <ConvertMoney />
      <div>-------------------------------------------</div>
      <Learn />
      <div>-------------------------------------------</div>
      <Button
        title="Click me!"
        href="https://www.google.com/"
        onClick={() => console.log("haha")}
      />
      <div>-------------------------------------------</div>
      <h2>CHILDREN PROPS</h2>
      <ChildrenProps data={cars}>{(car) => <li>{car}</li>}</ChildrenProps>
      <div>-------------------------------------------</div>
      <h2>useState()</h2>
      <RandomNumberHook />
      <div>-------------------------------------------</div>
      <h2>TODOLIST</h2>
      <TodoList />
      <div>-------------------------------------------</div>
      <h2>useEffect()</h2>
      <Content />
      <div>-------------------------------------------</div>
      <h2>useLayoutEffect()</h2>
      <MyApp />
      <div>-------------------------------------------</div>
      <h2>useRef()</h2>
      <CountDown />
      <div>-------------------------------------------</div>
      <h2>memo</h2>
      <MyMemo />
      <div>-------------------------------------------</div>
      <h2>useMemo()</h2>
      <MyUseMemo />
      <div>-------------------------------------------</div>
      <h2>useReducer()</h2>
      <MyUseReducer />
      <TodoList2 />
      <div>-------------------------------------------</div>
      <Apps />
    </>
  );
}
export default App;
