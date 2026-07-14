/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const n = temperatures.length;
    const stack = [];
    const ans = new Array(n).fill(0);

    for(let i=n-1; i>=0; i--){

        while(stack.length>0 && temperatures[stack[stack.length-1]] <= temperatures[i])
            stack.pop();

        if(stack.length==0)
            ans[i] = 0;
        else{
            ans[i] = stack[stack.length-1] - i;
        }
        stack.push(i);
    }
    return ans;
};