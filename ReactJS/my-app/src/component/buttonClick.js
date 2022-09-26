import React from "react";

class ButtonClick extends React.Component {
  constructor(props) {
    super(props);
    this.state = { index: 1 };
  }
  render() {
    return (
      <>
        <p>Gia tri: {this.state.index}</p>
        <button
          onClick={() => {
            this.setState({ index: this.state.index + 1 });
          }}
        >
          Tang
        </button>
        <button
          onClick={() => {
            this.setState({ index: this.state.index - 1 });
          }}
        >
          Giam
        </button>
      </>
    );
  }
}

export default ButtonClick;

// const ButtonClick = () => {
//   let count = 0;
//   const increase = () => {
//     count += 1;
//     console.log(count);
//   };
//   const decrease = () => {
//     count -= 1;
//     console.log(count);
//   };
//   return (
//     <>
//       <button onClick={increase}>Tang</button>
//       <button onClick={decrease}>Giam</button>
//     </>
//   );
// };

// export default ButtonClick;
