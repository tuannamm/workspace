import React, { Component } from "react";

class Conditional extends Component {
  render() {
    let login = true;
    if (login) {
      return <h3>Login success</h3>;
    } else {
      return <h3>Login failed</h3>;
    }
  }
}

export default Conditional;
