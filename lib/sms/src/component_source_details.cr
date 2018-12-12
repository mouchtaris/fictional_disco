# vim: et ts=2 sw=2

module ComponentSourceDetails
  @mod_name : String
  @comp_name : String
  include ConfDirViews  # => conf_*
  include SourceDetails  # => polymorphic inheritance
  include Sagas  # => saga_*

  def mod_name
    @mod_name
  end

  def comp_name
    @comp_name
  end

  #@ override SourceDetails
  def path_suffix
    [
      @mod_name,
      "#{@comp_name}.cpp",
    ]
  end

  #@ override SourceDetails
  def file_header_saga
      saga_include_header(@comp_name) +
      saga_include_header("sacl") +
      saga_empty_line +
      saga_define_sacl(@mod_name, @comp_name) +
      saga_open_modspace(mod_name)
  end

  #@ override SourceDetails
  def file_footer_saga
      saga_close_modspace
  end
end
