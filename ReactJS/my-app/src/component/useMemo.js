import { useState, useMemo, useRef, useEffect } from "react";

// useMemo: tránh thực hiện một logic nào đó không cần thiết

const MyUseMemo = () => {
  const [name, setName] = useState("");
  const [price, setPrice] = useState("");
  const [products, setProduct] = useState([]);

  const nameRef = useRef();

  const handleClick = () => {
    setProduct([
      ...products,
      {
        name,
        price: +price,
      },
    ]);
    setName("");
    setPrice("");
    nameRef.current.focus();
  };

  const total = useMemo(() => {
    let result = products.reduce((value, product) => value + product.price, 0);
    return result;
  }, [products]);

  return (
    <>
      <input
        ref={nameRef}
        value={name}
        onChange={(e) => setName(e.target.value)}
        placeholder="enter name"
      />
      <br />
      <input
        value={price}
        onChange={(e) => setPrice(e.target.value)}
        placeholder="enter price"
      />
      <br />
      <button onClick={handleClick}>ADD</button>
      Total: {total}
      {products.map((product, index) => (
        <li key="index">
          {product.name} - {product.price}
        </li>
      ))}
    </>
  );
};

export default MyUseMemo;
