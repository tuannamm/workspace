//Gọi React và useState
import React, { useState } from "react";
export default function RandomNumberHook() {
  const [count, setCount] = useState(1); //Sử dụng useEffect() như componentDidUpdate
  const [infor, setInfor] = useState({
    name: "Tuan Nam",
    age: 21,
  });
  const [cars, setCars] = useState(["Bugatti", "Roll-Royce", "Maybach"]);
  const gifts = ["CPU I9", "RAM 32GB", "RGB Keyboard"];
  const [gift, setGift] = useState();
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const courseList = [
    {
      id: 1,
      name: "HTML, CSS",
    },
    {
      id: 2,
      name: "Javascript",
    },
    {
      id: 3,
      name: "ReactJS",
    },
  ];
  const [checked, setChecked] = useState([]);
  const handleChange = (id) => {
    setChecked((prev) => {
      const isChecked = checked.includes(id);
      if (isChecked) {
        return checked.filter((item) => item !== id);
      } else {
        return [...prev, id];
      }
    });
  };

  return (
    <>
      <h3>{count}</h3>
      <button
        onClick={() => {
          setCount(count + 1);
        }}
      >
        Increase
      </button>
      <button
        onClick={() => {
          setCount(count - 1);
        }}
      >
        Decrease
      </button>

      <div>---------------------</div>
      <button
        onClick={() =>
          setInfor({
            ...infor,
            address: "Sai Gon",
          })
        }
      >
        Change Infor
      </button>
      <p>{JSON.stringify(infor)}</p>
      <div>---------------------</div>
      <button
        onClick={() => {
          setCars((prevState) => {
            return [...prevState, "Lamboghini"];
          });
        }}
      >
        Add car
      </button>
      <h3>{cars}</h3>
      <div>---------------------</div>
      <h3>{gift || "Chua co phan thuong"}</h3>
      <button
        onClick={() => {
          setGift(gifts[Math.floor(Math.random() * gifts.length)]);
        }}
      >
        Lay thuong
      </button>
      <div>---------------------</div>
      <h3>Two-ways biding</h3>
      <input value={name} onChange={(e) => setName(e.target.value)} />
      <p>Name: {name}</p>
      <button onClick={() => setName("Tuan Nam")}>Change</button>
      <div>---------------------</div>
      <label>Email</label>
      <input
        type="email"
        value={email}
        onChange={(e) => setEmail(e.target.value)}
      />
      <label>Password</label>
      <input
        type="password"
        value={password}
        onChange={(e) => setPassword(e.target.value)}
      />
      <button
        onClick={() =>
          console.log({
            email,
            password,
          })
        }
      >
        Submit
      </button>
      <div>---------------------</div>
      <div>
        {courseList.map((course) => (
          <div key={course.id}>
            <input
              type="checkbox"
              onChange={() => handleChange(course.id)}
              checked={checked.includes(course.id)}
            />
            {course.name}
          </div>
        ))}
      </div>
      <div>---------------------</div>
    </>
  );
}
