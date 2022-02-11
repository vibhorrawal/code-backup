// only 1-9, +,-,*,/,= supported

function calculator() {
    let exprn = '';
    return function(sign) {
        console.debug(sign);
        sign === '=' ? (console.log(eval(exprn)), exprn = '') : exprn += sign;
    }
}

let calc = calculator();

calc(1)
calc('+')
calc(2)
calc('=')

calc(2) 
calc('**')
calc(3)
calc('=')

function useCalculator(calc, keys) {
    [...keys].map(calc)
}

useCalculator(calc, "5*3+2=")