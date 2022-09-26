import React, { Component } from "react";

const VNDtoUSD = (props) => {
  function convert(vnd) {
    return vnd / 23632;
  }
  return (
    <>
      <span>VND</span>
      <input
        onChange={(e) => {
          const vnd = e.target.value;
          const usd = convert(vnd);
          props.onHandleChange({
            vnd,
            usd,
          });
        }}
        value={props.value}
      />
    </>
  );
};

const USDtoVND = (props) => {
  function convert(usd) {
    return usd * 23632;
  }
  return (
    <>
      <span>USD</span>
      <input
        onChange={(e) => {
          const usd = e.target.value;
          const vnd = convert(usd);
          props.onHandleChange({
            vnd,
            usd,
          });
        }}
        value={props.value}
      />
    </>
  );
};

export default class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      usd: 0,
      vnd: 0,
    };
  }
  handleChange = (data) => {
    this.setState(data);
  };
  render() {
    return (
      <div>
        <USDtoVND onHandleChange={this.handleChange} value={this.state.usd} />
        <VNDtoUSD onHandleChange={this.handleChange} value={this.state.vnd} />
      </div>
    );
  }
}
