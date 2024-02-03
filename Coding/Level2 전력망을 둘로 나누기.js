function findConnect(st, w, n) {
    var num = 0;
    var visit = new Array(101).fill(false);
    var queue = new Array();
    queue.push(st);
    while (queue.length > 0) {
        var cur = queue[0];
        queue.shift();
        if(visit[cur]) continue;
        visit[cur] = true;
        num = num + 1;
        for(var i = 1; i <= n; i++) {
            if(!visit[i] && w[cur][i]) {
                queue.push(i);
            }
        }
    }
    return num;
}

function solution(n, wires) {
    var answer = 999;
    var w = new Array(n+1);
    for(var i = 1; i <= n; i++) {
        w[i] = new Array(n+1).fill(false);
    }
    
    for(var i in wires) {
        w[wires[i][0]][wires[i][1]] = true;
        w[wires[i][1]][wires[i][0]] = true;
    }
    for(var i in wires) {
        var a = wires[i][0];
        var b = wires[i][1];
        w[a][b] = false;
        w[b][a] = false;
        var num = findConnect(a, w, n);
        w[a][b] = true;
        w[b][a] = true;
        answer = Math.min(answer, Math.abs(n - 2*num));
    }

    return answer;
}
