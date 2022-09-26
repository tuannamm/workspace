import React, { Component } from "react";

const withHoverOpacity = (ImageComponent) => {
  return class extends Component {
    constructor(props) {
      super(props);
      this.state = {
        opacity: 1,
      };
      this.onMouseLeave = this.onMouseLeave.bind(this);
      this.onMouseEnter = this.onMouseEnter.bind(this);
    }
    onMouseLeave() {
      this.setState({
        opacity: 1,
      });
    }
    onMouseEnter() {
      this.setState({
        opacity: 0.5,
      });
    }

    render() {
      return (
        <>
          <div
            style={this.state.opacity}
            onMouseEnter={this.onMouseEnter}
            onMouseLeave={this.onMouseLeave}
          >
            <ImageComponent />
          </div>
        </>
      );
    }
  };
};
const Image1 = (props) => {
  return <img src="https://freetuts.net/public/logo/logo.png" alt="" />
}
const Image2 = (props) => {
  return <img src="" alt="" />
}
