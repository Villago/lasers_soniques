function get_parent_name()
{
	if (this.patcher.parentpatcher)
    	outlet(0, this.patcher.parentpatcher.name);
	else
		error("get_parent_name: this should be called from zsa.open.\n");
}

function get_description_for_object(name)
{
	var dict = max.getrefdict(name);
	if (typeof(dict) == "object") {
		var digest = dict.get("digest");
		if (typeof(digest) == "string")
			outlet(0, "set", digest);
		else
			outlet(0, "set", "description not found");
	}
}

function getpath(what)
{
	var zsaPath;

	if (arguments.length != 1) {
		error("should be something like \"getpath externals\"\n");
		return;
	}

	// list all the packages
	var p = new Packages;
	var paths = p.getsubpaths(".", 1);

	// find the package-info files and search the zsa.descriptors package
	for (var i = 0; i < paths.length; i++) {
		var f = new File(paths[i]+ "/package-info.json");

		if (f.isopen) {	// if there's a package-info.json file in that package folder
			f.close();

			var d = new Dict();
			d.import_json(paths[i]+ "/package-info.json");	// load package-info.json in a dictionary
			if (d.get("name") == "zsa.descriptors") {		// to see if the package name is zsa.descriptors
				zsaPath = paths[i];
			}
		}
	}

	if (zsaPath)
		outlet(0, zsaPath + "/" + what);
	else	
		error("zsa.descritors is not properly installed, can't find the package-info.json file!");
}

function update_description(name)
{
	var dict = max.getrefdict(name);
	var daddy = this.patcher.parentpatcher;
	
	if (daddy) {
		var title = daddy.getnamed("zsa_title");
		if (title)
			title.set(name);
		
		var desc = daddy.getnamed("zsa_description");
		if (desc)
			desc.set(dict.get("digest"));
	}
}