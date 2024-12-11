"use strict";

/** Модель загрузки данных. */
class DataLoader {
    static emptyGraphDataTemplate = { vertices: [], edges: [] };

    constructor() {
        this.graphData = DataLoader.emptyGraphDataTemplate;
    }

    // getLocalGraphData() {
    //     // jsonGraphData загружена в html страничке
    //     this.graphData = JSON.parse(jsonGraphData);
    //     return this.graphData;
    // }

    async loadGraphData() {
        // const href = window.location.href; // http://localhost:3001/user/q000/AlgoViewPage.html
        // const mainPath = href.slice(0, href.lastIndexOf("/")); // http://localhost:3001/user/q000
        // const jsonGraphDataUrl = mainPath + "/Json_models/graphData.json"; // http://localhost:3001/user/d000/Json_models/graphData.json\

        // теперь jsonGraphDataUrl инициализируется в result_task.html
        // https://learn.javascript.ru/url

        const url = new URL(window.location.href);
        const jsonGraphDataUrl = url.searchParams.get("jsonGraphDataUrl");

        console.log(
            `[algoview.dataloader] jsonGraphDataUrl = ${jsonGraphDataUrl}.`
        );

        let rawData = "";

        await $.ajax({
            type: "GET",
            url: jsonGraphDataUrl,
            headers: { "cache-control": "no-cache" }, // !!!
            success: function (data) {
                console.log("[algoview.dataloader] data from ajax.get: ", data);
                rawData = data;
            },
        });

        this.graphData = rawData;
        return this.graphData;
    }
}
