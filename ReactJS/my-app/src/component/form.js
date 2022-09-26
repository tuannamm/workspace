import React, { Component } from "react";

class Form extends Component {
  constructor(props) {
    super(props);
    this.state = {
      email: "",
      password: "",
    };
  }

  // lấy giá trị của input sau đó nhập vào state
  changeInputValue = (e) => {
    this.state({
      [e.target.name]: e.target.value,
    });
  };

  // kiểm tra gía trị khi submit vào form
  validationForm = () => {
    let returnData = {
      error: false,
      msg: "",
    };
    const { email, password } = this.state;

    const re = /\S+@\S+\.\S+/;

    if (!re.test(email)) {
      returnData = {
        error: true,
        msg: "Không đúng định dạng email",
      };
    }

    if (password.length < 8) {
      returnData = {
        error: true,
        msg: "Mật khẩu phải lớn hơn 8 ký tự",
      };
    }
    return returnData;
  };

  // submit form
  submitForm = (e) => {
    e.preventDefault();

    //Gọi hàm validationForm() dùng để kiểm tra form
    const validation = this.validationForm();

    //Kiểm tra lỗi của input trong form và hiển thị
    if (validation.error) {
      alert(validation.msg);
    } else {
      alert("Submit form success");
    }
  };

  render() {
    return (
      <>
        <h2>LOGIN FORM</h2>
        <form onSubmit={(e) => this.submitForm(e)} />
        <lable htmlFor="text">Email: </lable>
        <input
          type="text"
          name="email"
          placeholder="Email"
          onChange={(e) => this.changeInputValue(e)}
        />
        <lable htmlFor="text">Password: </lable>
        <input
          type="password"
          name="password"
          placeholder="Password"
          onChange={(e) => this.changeInputValue(e)}
        />
        <button type="submit">Submit</button>
      </>
    );
  }
}

export default Form;
