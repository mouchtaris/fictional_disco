# vim: et ts=2 sw=2

module ModMainSourceDetails
  include SourceDetails  # polymorphic inheritance

  #@ override SourceDetails
  def path
    File.join(
      conf_sms_root,
      conf_project_root,
      "src",
      "#{@mod_name}",
    )
  end
end
