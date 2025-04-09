// Функция для добавления случайного параметра версии к URL ресурса
function addVersionToUrl(url) {
    if (!url) return url;
    const timestamp = new Date().getTime();
    const separator = url.includes("?") ? "&" : "?";
    return `${url}${separator}v=${timestamp}`;
}

// Функция для обновления версий всех ресурсов
function updateResourceVersions() {
    // Обновляем версии для всех скриптов
    document.querySelectorAll("script[src]").forEach((script) => {
        const originalSrc = script.getAttribute("src");
        script.src = addVersionToUrl(originalSrc);
    });

    // Обновляем версии для всех стилей
    document.querySelectorAll('link[rel="stylesheet"]').forEach((link) => {
        const originalHref = link.getAttribute("href");
        link.href = addVersionToUrl(originalHref);
    });
}

// Запускаем обновление версий при загрузке страницы
document.addEventListener("DOMContentLoaded", updateResourceVersions);
