# vim: et ts=2 sw=2

module SourceDetails
  include ConfDirViews  # => conf_*

  def source_path_prefix
    [
      conf_sms_root,
      conf_project_root,
      "src",
    ]
  end

  def mkpath(elements : Array(String))
    if elements.empty?
      ""
    else
      elements.reduce { |a, b| File.join a, b }
    end
  end

  def path : String
    mkpath(source_path_prefix + path_suffix)
  end

  #@ abstract
  def path_suffix
    raise "Unimplemented"
  end

  def file_header_saga : Array(LineAdder)
    raise "Unimplemented"
  end

  def file_footer_saga : Array(LineAdder)
    raise "Unimplemented"
  end
end
