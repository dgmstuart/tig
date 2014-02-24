#include "request.h"
#include "line.h"
#include "keys.h"
#include "view.h"
		info = find_line_info(argv[0], strlen(argv[0]), FALSE);
		info = get_line_info(index);
		const int len = get_line_info(LINE_DIFF_HEADER)->linelen;
struct help_request_iterator {
	struct view *view;
	struct keymap *keymap;
	bool add_title;
	const char *group;
};
static bool
help_open_keymap(void *data, const struct request_info *req_info, const char *group)
{
	struct help_request_iterator *iterator = data;
	struct view *view = iterator->view;
	struct keymap *keymap = iterator->keymap;
	const char *key = get_keys(keymap, req_info->request, TRUE);
	if (req_info->request == REQ_NONE || !key || !*key)
		return TRUE;
	if (iterator->add_title && help_open_keymap_title(view, keymap))
		return FALSE;
	iterator->add_title = FALSE;
	if (iterator->group != group) {
		add_line_text(view, group, LINE_HELP_GROUP);
		iterator->group = group;
	add_line_format(view, LINE_DEFAULT, "    %-25s %-20s %s", key,
			enum_name(*req_info), req_info->help);
	return TRUE;
}
static void
help_open_keymap_run_requests(struct help_request_iterator *iterator)
{
	struct view *view = iterator->view;
	struct keymap *keymap = iterator->keymap;
	char buf[SIZEOF_STR];
	const char *group = "External commands:";
	int i;

	for (i = 0; TRUE; i++) {
		if (!req)
			break;

		if (req->keymap != keymap)
		if (iterator->add_title && help_open_keymap_title(view, keymap))
		iterator->add_title = FALSE;
	for (keymap = get_keymaps(); keymap; keymap = keymap->next) {
		struct help_request_iterator iterator = { view, keymap, TRUE };

		if (foreach_request(help_open_keymap, &iterator))
			help_open_keymap_run_requests(&iterator);
	}
	struct line_info *info = get_line_info(type);