const test = (expr) => {
  switch (expr) {
    case 'Oranges':
    case 'Mangoes':
    case 'Papayas':
      console.log(expr);
      // expected output: "Mangoes and papayas are $2.79 a pound."
      break;
    default:
      console.log(`Sorry, we are out of ${expr}.`);
  }
};
test('Mangoes');
