"use strict";
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
Object.defineProperty(exports, "__esModule", { value: true });
var fs_1 = require("fs");
var randint = function (minimum, maximum) {
    return Math.floor(Math.random() * (maximum - minimum + 1)) + minimum;
};
var div = function (a, b) {
    return Math.floor(a / b);
};
var shuffle = function (array) {
    var _a;
    var shuffledArray = __spreadArray([], array, true);
    for (var i = shuffledArray.length - 1; i > 0; i--) {
        var j = Math.floor(Math.random() * (i + 1));
        _a = [shuffledArray[j], shuffledArray[i]], shuffledArray[i] = _a[0], shuffledArray[j] = _a[1];
    }
    return shuffledArray;
};
var sum = function (arr) {
    var integer = 0;
    arr.map(function (value) {
        integer += value;
    });
    return integer;
};
var avg = function (arr) {
    return sum(arr) / arr.length;
};
var min = function (arr) {
    var minimum = arr[0];
    arr.map(function (value) {
        if (value < minimum) {
            minimum = value;
        }
    });
    return minimum;
};
var max = function (arr) {
    var maximum = arr[0];
    arr.map(function (value) {
        if (value > maximum) {
            maximum = value;
        }
    });
    return maximum;
};
var trim = function (arr) {
    var returned = [];
    arr.map(function (str) {
        if (str.length !== 0) {
            returned.push(str);
        }
    });
    return returned;
};
var ex1 = function () {
    var arr = [];
    var nb_values_sup_sevent = 0;
    var average = 0;
    var minimum = 0;
    var maximum = 0;
    var stop = true;
    while (stop) {
        var random = randint(1, 10);
        arr.push(random);
        if (random === 7) {
            stop = false;
        }
    }
    console.log(arr);
    average = avg(arr);
    minimum = min(arr);
    maximum = max(arr);
    console.log(average);
    console.log(minimum);
    console.log(maximum);
    arr.map(function (value) {
        if (value > 7) {
            nb_values_sup_sevent++;
        }
    });
    console.log(nb_values_sup_sevent);
};
var voyelles_founder = function (text) {
    var text_arr = text.split("");
    var voyelles = ["a", "e", "i", "o", "u", "y"];
    var founded = { "a": 0, "e": 0, "i": 0, "o": 0, "u": 0, "y": 0 };
    var maximum = null;
    text_arr.map(function (char) {
        if (voyelles.includes(char)) {
            if (founded[char] >= 0) {
                founded[char] += 1;
            }
        }
    });
    for (var key in founded) {
        var value = founded[key];
        if (!maximum) {
            maximum = [key, value];
        }
        else if (maximum[1] < value) {
            maximum = [key, value];
        }
    }
    return maximum;
};
var replace = function (c1, c2, s) {
    var returned = "";
    var string_splited = s.split("");
    string_splited.map(function (char) {
        if (char === c1) {
            returned += c2;
        }
        else {
            returned += char;
        }
    });
    return returned;
};
var sentence_counter = function (file_path) {
    var text = (0, fs_1.readFileSync)(file_path, { encoding: "utf-8" });
    var replaced_text = text.replace('.', '|').replace('?', '|').replace('!', '|');
    var sentences = replaced_text.split("|");
    var sentences_transformed = trim(sentences);
    return sentences_transformed.length;
};
var password_generator = function (size) {
    var ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz';
    var ascii_uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    var digits = '0123456789';
    var password_array = [];
    var upper_size = div(size, 3);
    var lower_size = div(size, 3);
    var digits_size = size - (div(size, 3) * 2);
    for (var k = 0; k < upper_size; k++) {
        password_array = __spreadArray(__spreadArray([], password_array, true), [ascii_uppercase[randint(0, ascii_uppercase.length - 1)]], false);
    }
    for (var k = 0; k < lower_size; k++) {
        password_array = __spreadArray(__spreadArray([], password_array, true), [ascii_lowercase[randint(0, ascii_lowercase.length - 1)]], false);
    }
    for (var k = 0; k < digits_size; k++) {
        password_array = __spreadArray(__spreadArray([], password_array, true), [digits[randint(0, digits.length - 1)]], false);
    }
    var shuffled = shuffle(password_array);
    return shuffled.join("");
};
ex1();
console.log(voyelles_founder("coucou c'est moi"));
console.log(voyelles_founder("gdfg hjklkm nbvcwxq dfsgdh fjkn"));
console.log(replace("o", "e", "coucou c'est moi"));
console.log(replace("k", "j", "coucou c'est moi"));
console.log(replace(" ", "\n", "gdfg hjklkm nbvcwxq dfsgdh fjkn"));
console.log(sentence_counter("./test.txt"));
console.log(password_generator(12));
console.log(password_generator(32));
console.log(password_generator(64));
