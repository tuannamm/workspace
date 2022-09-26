import React, { Component } from "react";

class Change extends Component {
  constructor(props) {
    super(props);
    this.state = {
      textAreaChange: "",
      buttonClick: "",
      mouseOver: "",
    };
    this.mouseOver = this.mouseOver.bind(this);
  }
  changeText(e) {
    this.setState({
      textAreaChange: e.value.target,
    });
  }
  mouseOver() {
    this.setState({
      mouseOver: this.state.mouseOver + "hahahaha",
    });
  }
  render() {
    return (
      <>
        <div>Show: {this.state.buttonClick}</div>
        <button
          onClick={() => {
            this.setState({
              buttonClick: this.state.buttonClick + "hihihi",
            });
          }}
        >
          Click me
        </button>
        <div>
          <textarea
            onChange={(e) => this.changeText(e)}
            placeholder="Nhap vao"
          ></textarea>
        </div>
        <div>Result: {this.state.textAreaChange}</div>
        <h2 onMouseOver={this.mouseOver}>Ngon dung vo?</h2>
        <div>Result: {this.state.mouseOver}</div>
      </>
    );
  }
}

export default Change;
