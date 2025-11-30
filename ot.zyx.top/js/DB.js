function hash(s) {
	var ans = 0;
	for (var i = 0; i < s.length; i++) {
		ans += s[i].charCodeAt() * 130;
		ans %= 998244353;
	}
	return ans;
}

function query(event) {
	if (event.type == "checkuser") {
		return localStorage.getItem("zyxOT-v3-username_checksum") == md5(event.user + hash(localStorage.getItem("zyxOT-v3-user=" + event.user + "?password")));
	}
}
function update(event) {
	if (event.type == "login") {
		if (md5(event.password) == localStorage.getItem("zyxOT-v3-user=" + event.user + "?password")) {
			localStorage.setItem("zyxOT-v3-username", event.user);
			localStorage.setItem("zyxOT-v3-username_checksum", md5(event.user + hash(localStorage.getItem("zyxOT-v3-user=" + event.user + "?password"))));
		}
	}
	else if (event.type == "logout") {
		localStorage.removeItem("zyxOT-v3-username");
		localStorage.removeItem("zyxOT-v3-username_checksum");
		location.href = localStorage.getItem("zyxOT-v3-deploy") + "ot.zyx.top.html";
	}
}

class SQLite {
	query(event) {
		return eval(event);
	}
	update(event) {
		return eval(event);
	}
}

window.DB = new SQLite;
