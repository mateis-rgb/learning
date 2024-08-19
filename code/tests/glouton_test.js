var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
var division = function (a, b) {
    return Math.floor(a / b);
};
var retirer_element = function (arr, indice) {
    if (arr.length === 0) {
        return [];
    }
    if (indice > arr.length) {
        throw new Error("L'indice de l'élément à supprimer ne doit pas dépasser la taille du tableau");
    }
    var new_arr = [];
    for (var k = 0; k < arr.length; k++) {
        if (k !== indice) {
            new_arr.push(arr[k]);
        }
    }
    return new_arr;
};
var rendu_monnaie = function (montant, systeme_monnaie) {
    if (systeme_monnaie.length === 0) {
        throw new Error("Le système monnaitaire ne doit pas être vide.");
    }
    var monnaie = systeme_monnaie[0];
    var str_monnaie = monnaie.toString();
    if (montant % monnaie === 0) {
        return { str_monnaie: montant / monnaie };
    }
    var new_systeme_monnaie = retirer_element(systeme_monnaie, 0);
    return __assign({ str_monnaie: division(montant, monnaie) }, rendu_monnaie(montant % monnaie, new_systeme_monnaie));
};
var systeme_monnaie = [500, 200, 100, 50, 20, 10, 5, 2, 1];
console.log(rendu_monnaie(999, systeme_monnaie));
