import React, { Component } from "react";
const Notification = (props) => {
  if (props.isShow) {
    return (
      <ul>
        <h4>HELLO</h4>
        <h4>AONE</h4>
      </ul>
    );
  } else {
    return null;
  }
};
export default class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      isShowNotification: false,
    };
  }
  render() {
    const { isShowNotification } = this.state;

    return (
      <div>
        <h3>SHOW - HIDE</h3>
        <button
          onClick={() => {
            this.setState({
              isShowNotification: !isShowNotification,
            });
          }}
        >
          {isShowNotification ? "Ẩn" : "Hiển thị"}
        </button>
        <Notification isShow={isShowNotification} />
      </div>
    );
  }
}
