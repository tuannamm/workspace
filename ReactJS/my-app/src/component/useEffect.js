import React, { useEffect, useState } from "react";

// side effects: khi một sự kiện xảy ra gây tác động đến dữ liệu phần mềm

// 1. useEffect(callback)
//-> Gọi callback mỗi khi component re-render
//-> Gọi callback sau khi component thêm element vào DOM (sau khi return)
// 2. useEffect(callback, [])
//-> Chỉ gọi callback 1 lần sau khi component sau khi component mounted
// 3. useEffect(callback, [deps])
//-> Callback sẽ được gọi lại mỗi khi deps thay đổi
// ------------------
//1. Callback luôn được gọi sau khi component mounted
//2. Cleanup function được gọi trước khi component bị unmounted
//3. Cleanup function luôn được gọi trước khi callback được gọi (trừ lần mounted)

const Content = () => {
  const [title, setTitle] = useState("");
  const [posts, setPost] = useState([]);
  const [types, setType] = useState("");
  const [onTop, setOnTop] = useState(false);
  const [width, setWidth] = useState(window.innerWidth);
  const [countdown, setCountdown] = useState(180);
  const [avatar, setAvatar] = useState();

  const tabs = ["posts", "comments", "albums"];

  //---------------------------------------------------------------------------
  useEffect(() => {
    document.title = title;
  });

  //---------------------------------------------------------------------------
  useEffect(() => {
    fetch(`https://jsonplaceholder.typicode.com/${types}`)
      .then((res) => res.json())
      .then((post) => {
        setPost(post);
      });
  }, [types]);

  //---------------------------------------------------------------------------
  useEffect(() => {
    const handleScroll = () => {
      setOnTop(window.scrollY > 200);
    };
    window.addEventListener("scroll", handleScroll);

    //Cleanup function
    return () => {
      window.removeEventListener("scroll", handleScroll);
    };
  }, []);

  //---------------------------------------------------------------------------
  useEffect(() => {
    const handleResize = () => {
      setWidth(window.innerWidth);
    };

    window.addEventListener("resize", handleResize);

    return () => {
      window.removeEventListener("resize", handleResize);
    };
  });

  //---------------------------------------------------------------------------
  useEffect(() => {
    const timerID = setInterval(() => {
      if (countdown > 0) setCountdown((prev) => prev - 1);
      if (countdown <= 0) setCountdown(180);
    }, 1000);

    return () => clearInterval(timerID);
  }, []);

  //---------------------------------------------------------------------------
  useEffect(() => {
    return () => {
      avatar && URL.revokeObjectURL(avatar.preview);
    };
  }, [avatar]);
  const handlePreviewAvatar = (e) => {
    const file = e.target.files[0];

    file.preview = URL.createObjectURL(file);

    setAvatar(file);
  };

  return (
    <>
      <input value={title} onChange={(e) => setTitle(e.target.value)} />
      {tabs.map((tab) => (
        <button
          onClick={() => setType(tab)}
          style={
            types === tab
              ? {
                  color: "white",
                  backgroundColor: "purple",
                }
              : {}
          }
        >
          {tab}
        </button>
      ))}
      <ul>
        {posts.map((post) => (
          <li key={post.id}>{post.title || post.name}</li>
        ))}
      </ul>
      {onTop && (
        <button
          style={{
            position: "fixed",
            right: 20,
            bottom: 20,
          }}
        >
          Go to top
        </button>
      )}
      <h1>Width: {width}</h1>
      <h1>Countdown: {countdown}</h1>
      <input type="file" onChange={handlePreviewAvatar} />
      {avatar && <img src={avatar.preview} alt="" width="80%" />}
    </>
  );
};

export default Content;
