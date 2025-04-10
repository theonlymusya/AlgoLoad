function print(...args) {
    const timestamp = new Date().toISOString().split("T")[1].slice(0, -1);
    const prefix = `🧩 [AlgoView ${timestamp}]`;

    console.log(prefix, ...args);
}
