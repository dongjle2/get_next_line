char	*get_next_line(int fd)
{
	static char		*stored_str;
	ssize_t			nl_idx;

	while (1)
	{
		nl_idx = find_nl_idx(stored_str);
		if (0 <= nl_idx)
			return (ret_from_stored_string(&stored_str, nl_idx));
		else
			return (start_read(&stored_str, fd));
	}
	// return (stored_str);
}