str1 = prompt("Nhập string 1");
str2 = prompt("Nhập string 2");

function merge2String(str1, str2) {
    let a = str1.length;
    let b = str2.length;
    let str3;
    let i = 0, j = 0;
    while (i <= a && j <= b) {
        str3 = str3 + str1.slice(i, i + 1) + str2.slice(j, j + 1);
        if (i == a) {
            a[i] = '';
        }
        if (j == b) {
            b[j] = '';
        }
        i++;
        j++;
    }
    str4 = str3.slice(9, str3.length)
    console.log(str4);
}
merge2String(str1, str2);